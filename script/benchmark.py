#!/usr/bin/env python3
"""
Does benchmark and produce some graphs

Copyright (C) 2019  Qian Yu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""

import os
import subprocess
import io
import pandas as pd
import matplotlib.pyplot as plt
from jinja2 import Environment, BaseLoader

build_path = os.path.join("buildperf")

benchmark = os.path.join(build_path, "test", "switch_benchmark")

out = subprocess.check_output([benchmark, "--benchmark_format=csv"])
stream = io.StringIO(out.decode())
stream.seek(0)
df = pd.read_csv(stream)

df["implementation"] = df["name"].apply(lambda x: x.split("<")[0])
df["number"] = df["name"].apply(lambda x: int(x.split("<")[1].split(">")[0]))

plt.style.use("ggplot")
plt.figure(figsize=(16, 12))
for implementation, group in df.groupby("implementation"):
    plt.plot(group["number"], group["cpu_time"], "o-", label=implementation)
plt.legend()

graph = "switch_benchmark.png"
plt.savefig(os.path.join("script", graph))

intervals = df[df["number"].isin({4, 8, 16, 32, 64, 128})]
table = intervals.pivot(index="implementation", columns="number")[
    "cpu_time"
].to_string()
print(table)

benchmark_md = """
# Benchmarks

Benchmarking is done against "hand-rolled" switch-case statements. The benchmark problem is inspired by mpark variant's [execute.mpark.cpp](https://github.com/mpark/variant/blob/benchmark/visit.1/execute.mpark.cpp)

![benchmark graph](./{{graph}})

```
{{table}}
```
"""

rendered = (
    Environment(loader=BaseLoader)
    .from_string(benchmark_md)
    .render(graph=graph, table=table)
)

with open("script/benchmark.md", "w") as fd:
    print(rendered, file=fd)
