#!/usr/bin/env python3
"""
A helper tool for creating integral_switch.h.
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
    cmd = argparse.ArgumentParser(__doc__)
    cmd.add_argument(
        "number",
        nargs="?",
        type=int,
        default=32,
        help="The height of the switch case statement",
    )
    cmd.add_argument(
        "--clangformatbin", required=True, help="Path to clang-format binary"
    )
    args = cmd.parse_args()
    dirname = os.path.dirname(__file__)
    env = Environment(loader=FileSystemLoader(dirname))
    template = env.get_template("integral_switch.tmpl")

    def formatRange(rng, fmt):
        for i in rng:
            yield fmt.format(i)

    out = template.render(number=args.number, formatRange=formatRange)
    formatted = clangFormat(args.clangformatbin, out)
    print(formatted)
