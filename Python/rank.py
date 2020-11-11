#!/usr/bin/env python3
import itertools as it
import os
from sys import argv 

def relation(A, B):
    metric = sum([int(a >= b) for a, b in zip(A, B)])
    if metric == len(A):
        return ">"
    elif metric == 0:
        return "<"
    else:
        return "#"

matrix = {}
for line in open(argv[1]):
    marks = line.strip().split()
    matrix[marks[0]] = [int(x) for x in marks[1:]]

keys = list(matrix.keys())
combo = it.combinations(keys, 2)
rels = set([])
for key1, key2 in combo:
    r = relation(matrix[key1], matrix[key2])
    if r == ">":
        rels.add(key1 + key2)
    elif r == "<":
        rels.add(key2 + key1)

rels = list(sorted(rels))

start = set([x[0] for x in rels])
ends = set([x[1] for x in rels])
both = start & ends

removables = set([])
rules = set([])
for x in start:
    for y in ends:
        if x + y not in rels:
            continue
        for z in both:
            if x + z in rels and z + y in rels:
                removables.add(x+y)
                rules.add(x+y + " <= " + x+z + " & " + z+y  )
print("ALL relations\n", rels)
print("Removables   \n", list(sorted(removables)))
print("Removal rules\n", list(sorted(rules)))
print("Minimal      \n", list(sorted(set(rels)^removables)))
minimal = sorted(set(rels) ^ removables)

with open("vanchi.dot", "w") as f:
    print("digraph vanchi {", file=f)
    for relation in minimal:
        print("\t%s -> %s;" %(relation[0], relation[1]), file=f)
    print("}", file=f)

os.system("dot -T png -o vanchi.png vanchi.dot")
