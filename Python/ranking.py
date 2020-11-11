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

def read_file(FILENAME):
    data = {}
    for line in open(FILENAME):
        marks_list = line.strip().split()
        data[marks_list[0]] = [int(x) for x in marks_list[1:]]
    return data


def total_relations(FILENAME):
    marks = read_file(FILENAME)
    students = marks.keys()
    combo = it.combinations(students, 2)
    rels = set()
    for student1, student2 in combo:
        rel = relation(marks[student1], marks[student2])
        if rel == ">":
            rels.add(student1 + student2)
        elif rel == "<":
            rels.add(student2 + student1)
    return list(sorted(rels))


def removables(rels):
    start = set([x[0] for x in rels])
    ends = set([x[1] for x in rels])
    both = start & ends

    removables = set()
    for x in start:
        for y in ends:
            if x + y not in rels:
                continue
            for z in both:
                if x + z in rels and z + y in rels:
                    removables.add(x+y)
    return removables

def minimal(relations):
    return sorted(set(relations) ^ removables(relations))
        
minimal_list = minimal(total_relations(argv[1]))
print(minimal_list)

with open("vanchi.dot", "w") as f:
    print("digraph vanchi {", file=f)
    print("\tgraph [fontname = \"Sans\"];", file=f)
    print("\tnode [fontname = \"Sans\"];", file=f)
    print("\tedge [fontname = \"Sans\"];", file=f)
    for relation in minimal_list:
        print("\t%s -> %s;" %(relation[0], relation[1]), file=f)
    print("}", file=f)

os.system("dot -T png -o vanchi.png vanchi.dot")
