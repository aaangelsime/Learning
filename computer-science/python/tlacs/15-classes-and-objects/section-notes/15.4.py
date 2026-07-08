""" 15.4 Improving our initializer """

class Point:

    def __init__(self, x = 0, y = 0):

        self.x = x
        self.y = y

p = Point(4, 2)
q = Point(6, 7)

print("P Coord: (", p.x, ",", p.y, ")" )
print("Q Coord: (", q.x, ",", q.y, ")" )
"""
P Coord: ( 4 , 2 )
Q Coord: ( 6 , 7 )
"""