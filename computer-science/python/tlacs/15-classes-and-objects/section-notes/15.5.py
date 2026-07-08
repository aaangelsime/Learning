""" 15.5 Adding other 'methods' to our class """

class Point:

    def __init__(self, x = 0, y = 0):

        self.x = x
        self.y = y

    def d_from_org(self):

        return ((self.x ** 2) + (self.y ** 2)) ** 0.5
    
    