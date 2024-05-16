# 42 - Fractol

<p align="center">
  <img src="https://github.com/BenjaminHThomas/fractol/assets/72560121/90710147-d9e0-4050-a31d-886df7c0e3ec" />
</p>

This is project to create an interactive Mandelbrot and Julia set in C using 42's minilibx API (X11).

It's not just a cool fractal that you'd see hanging on your stoner cousins wall, but actually an interesting mathematical concept. 
Please bear in mind however that I'm a former commerce grad, not a mathematician so the explanations may not be 100%.

## Introduction

The underlying function behind the graph is:
  f(z) = z^2 + c

so for example if z == 2 & c == 0, iterating this function would look like:
  4, 16, 256, 65536 .... and so on until infinity.

And that's where the central idea comes into play:
- Julia sets:        when iterating values of z, which are stable and which iterate to infinity?
- Mandelbrot sets:   when iterating values of c, which are stable and which iterate to infinity?

When you plot the values on a 2d plane, with the x-axis being real values (-1,0,1....n)
and the y-axis being complex imaginary values (-i, 0, i, 2i, 3i .... ni) (i = sqrt(-1)), you get graphs similar to the first image (mandelbrot) or like the below (Julia).

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/36/JuliaSet.35.png/1920px-JuliaSet.35.png" />
</p>

The colours are chosen arbitrarily, but the gradient is a measure of how unstable the value is. Typically black is completely stable, and blue is very unstable. With stability being a measure of how many iterations are required to reach infinity.
