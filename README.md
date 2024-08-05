# 42 - Fractol

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/21/Mandel_zoom_00_mandelbrot_set.jpg/1280px-Mandel_zoom_00_mandelbrot_set.jpg" />
</p>

This is project to create an interactive Mandelbrot and Julia set in C using 42's minilibx API (X11).

It's not just a cool fractal that you'd see hanging on your stoner cousins wall, but actually an interesting mathematical concept.

## Introduction

The underlying function behind the graph is:
  f(z) = z^2 + c

so for example if z == 2 & c == 0, iterating this function would look like:
  4, 16, 256, 65536 .... and so on until infinity.

With c being a complex number. The complex number has a real component and an imaginary component. c = a + bi with i being equal to the square root of -1.
If you're the same as me, you were probably quite confused by this because negative square roots aren't really possible. But that's the whole point, it's an abstraction.
The same way negative numbers aren't real, but they help us understand things better.
The important thing to remember is that i^2 = -1. Or it reverses the sign each time it's multiplied.

There's a really interesting video by veritasium here if you're interested:
\t https://www.youtube.com/watch?v=cUzklzVXJwo

And that's where the central idea comes into play:
  when iterating values of z, which are stable and which iterate to infinity?

When you plot the values on a 2d plane, with the x-axis being real values (-1,0,1....n)
and the y-axis being complex imaginary values (-i, 0, i, 2i, 3i .... ni) (i = sqrt(-1)), you get graphs similar to the first image (mandelbrot) or like the below (Julia).

The formula changes between different fractals but the underlying principle is the same.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/36/JuliaSet.35.png/1920px-JuliaSet.35.png" />
</p>

The colours are chosen arbitrarily, but the gradient is a measure of how unstable the value is. Typically black is completely stable, and blue is very unstable. With stability being a measure of how many iterations are required to reach infinity.
