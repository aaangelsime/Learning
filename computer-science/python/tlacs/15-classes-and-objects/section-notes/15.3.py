""" 15.3 Attributes """

"""
Object instaces have both attributes and methods.
We can modify the attributes in an instance using dot notation.

Example :
"""

""" Point class represents and manipulates (x,y) coords. """
class Point:

    def __init__(self):
        self.x = 0
        self.y = 0


p = Point() # Instantiate an object of type Point
q = Point() # Second Point

print(p.x, p.y, q.x, q.y) # Each point object has its own (x, y)
# Output : 0 0 0 0

p.x = 3
p.y = 3

print(p.x, p.y, q.x, q.y)
# Output : 3 3 0 0


