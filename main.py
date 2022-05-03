import sys
import copy
import random
class Clause():
    def __init__(self, value, isEmpty=False):
        self.p = set()
        self.n = set()
        self.isEmpty = isEmpty
        if not self.isEmpty:
            self.parse(value)

    def parse(self, value):
        arr = value.split("V")
        assert len(arr) >= 1
        for i in arr:
            c = i.strip()
            if len(c) == 0:
                continue
            if c[0] == "-":
                self.n.add(c[1:])
            else:
                self.p.add(c)

    def __eq__(self, right):
        return self.p == right.p and self.n == right.n

    def __hash__(self):

        return hash((frozenset(self.p), frozenset(self.n)))

    def subsum(self, other):
        return self.p.issubset(other.p) and self.n.issubset(other.n)

    def strict_subsum(self, right):
        sub = self.subsum(right)
        l1 = len(self.p) + len(self.n)
        l2 = len(right.p) + len(right.n)
        return sub and l1 < l2

    def __str__(self):
        values = []
        for value in self.p:
            values.append(value)
        for value in self.n:
            values.append("-" + value)
        return " V ".join(values)

    def remove_duplicates(self):
        for A in self.p:
            for B in self.n:
                if A == B:
                    self.p.remove(A)
                    self.n.remove(B)


def resolution(A, B):
    A = copy.deepcopy(A)
    B = copy.deepcopy(B)

    if(len(A.p & B.n) == 0 and len(A.n & B.p) == 0):
        return False

    if(len(A.p & B.n) != 0):
        a = random.sample(A.p & B.n, k=1)[0]
        A.p.remove(a)
        B.n.remove(a)
    else:
        a = random.sample(A.n & B.p, k=1)[0]
        A.n.remove(a)
        B.p.remove(a)


    C = Clause("", True)
    C.p = A.p | B.p
    C.n = A.n | B.n

    if len(C.p & C.n) != 0: #C is a tautology
        return False
    print()
    C.remove_duplicates()
    return C




def Solver(KB):
    KB_prim = set()
    while True:
        S = set()
        KB = copy.deepcopy(KB)
        KB_prim = copy.deepcopy(KB)
        for A in KB:
            for B in KB:
                if not (A==B):
                    C = resolution(A,B)
                    if C is not False:
                        S.add(C)

        if(len(S) == 0):
            return KB

        KB = Incorporate(S, KB)
        if(KB_prim == KB):
            return KB


def Incorporate(S, KB):
    for A in S:
        KB = Incorporate_clause(A,KB)
    return KB

def Incorporate_clause(A, KB):
    for B in KB:
        if(B.strict_subsum(A)):
            return KB
    delete = set()
    for B in KB:
        if(A.strict_subsum(B)):
            delete.add(B)
    for D in delete:
        KB.remove(D)


    KB.add(A)
    return KB

if __name__ == '__main__':
    '''print("Starting Task 1:")
    A = Clause("a V b V -c")
    B = Clause("c V b")
    sum = resolution(A, B)

    assert sum == Clause("a V b")
    A = Clause("a V b V -c")
    B = Clause("d V b V -g")
    sum = resolution(A, B)
    assert sum == False

    A = Clause("-b V c V t")
    B = Clause("-c V z V b")
    sum = resolution(A, B)
    assert sum == False'''

    print("")
    print("Starting Task 2:")
    KB = set()
    KB.add(Clause("-sun V -money V ice"))
    KB.add(Clause("-money V ice V movie"))
    KB.add(Clause("-movie V money"))
    KB.add(Clause("-movie V -ice"))
    KB.add(Clause("sun V money V cry"))
    sum = Solver(KB)

    print("Results")
    for i in sum:
        print(i)

