""" 15.2 User-Defined Compound Data Types """
"""
Example of creating our own user defined class : the 'Point'
"""

""" Point class represents and manipulates (x,y) coords. """
class Point:

    """ Create a new point at the origin"""
    """
    Notes : 
        the __init__ fn is the 'initializer method', it is called
        whenever a new instance of 'Point' is created, and gives
        the programmer the opportunity to set up attributes required 
        within the new instance.
    """
    def __init__(self):
        self.x = 0
        self.y = 0


p = Point() # Instantiate an object of type Point
q = Point() # Second Point

print(p.x, p.y, q.x, q.y) # Each point object has its own (x, y)
# Output : 0 0 0 0
