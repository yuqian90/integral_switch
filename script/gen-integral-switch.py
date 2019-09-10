#!/usr/bin/env python3
"""
A helper tool for creating integral_switch.h. This tool is only needed for development of
integral_switch. It's not needed for projects using integral_switch.

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
import argparse
import subprocess
import io
from jinja2 import Environment, FileSystemLoader


def clangFormat(bin, input):
    proc = subprocess.Popen(
        [bin], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    stdout, stderr = proc.communicate(input=input.encode())
    if stderr:
        raise subprocess.CalledProcessError(stderr)
    if proc.returncode:
        raise subprocess.CalledProcessError("returncode {}".format(proc.returncode))
    return stdout.decode()


if __name__ == "__main__":
    cmd = argparse.ArgumentParser(description=__doc__)
    cmd.add_argument(
        "number",
        nargs="?",
        type=int,
        default=32,
        help="The height of the switch case statement",
    )
    choices = ["integral_switch.tmpl", "benchmark_switch.tmpl"]
    cmd.add_argument(
        "--template",
        choices=choices,
        default=choices[0],
        help="File name of jinja template",
    )
    cmd.add_argument(
        "--clangformatbin", default="clang-format", help="Path to clang-format binary"
    )
    args = cmd.parse_args()
    dirname = os.path.dirname(__file__)
    env = Environment(loader=FileSystemLoader(dirname))
    template = env.get_template(args.template)

    def formatRange(rng, fmt):
        for i in rng:
            yield fmt.format(i)

    out = template.render(number=args.number, formatRange=formatRange)
    formatted = clangFormat(args.clangformatbin, out)
    print(formatted)
