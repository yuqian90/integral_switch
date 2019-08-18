#!/usr/bin/env python3
"""
Generate recursive swich case statement.
"""

import os
import argparse
from jinja2 import Environment, FileSystemLoader

if __name__ == "__main__":
    cmd = argparse.ArgumentParser(__doc__)
    cmd.add_argument("number", nargs="?", type=int, default=32,
                     help="The height of the switch case statement")
    args = cmd.parse_args()
    dirname = os.path.dirname(__file__)
    env = Environment(loader=FileSystemLoader(dirname))
    template = env.get_template("integral_switch.tmpl")

    def formatRange(rng, fmt):
        for i in rng:
            yield fmt.format(i)

    out = template.render(number=args.number, formatRange=formatRange)
    print(out)
