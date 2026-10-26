from manim import *

class SquareToCircle(Scene):
    def construct(self):
        square = Square(color=BLUE)
        circle = Circle(color=PINK, fill_opacity=0.5)

        self.play(Create(square))
        self.play(Transform(square, circle))
        self.wait()