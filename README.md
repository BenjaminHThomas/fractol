# Fractol Visualisation (C)

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

c is a complex numer. A complex number has a real component and an imaginary component. c = a + bi with i being equal to the square root of -1.
If you're the same as me, you were probably quite confused by this because negative square roots aren't really possible. But that's the whole point, it's an abstraction.
The same way negative numbers aren't real, but they help us understand things better.
The important thing to remember is that i^2 = -1. Or it reverses the sign each time it's multiplied.

There's a really interesting video by veritasium here if you're interested:
https://www.youtube.com/watch?v=cUzklzVXJwo

And that's where the central idea comes into play:
  when iterating values of z, which are stable and which iterate to infinity?

When you plot the values on a 2d plane, with the x-axis being real values (-1,0,1....n)
and the y-axis being complex imaginary values (-i, 0, i, 2i, 3i .... ni) (i = sqrt(-1)), you get graphs similar to the first image (mandelbrot) or like the below (Julia).

The formula changes between different fractals but the underlying principle is the same.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/36/JuliaSet.35.png/1920px-JuliaSet.35.png" />
</p>

The colours are chosen arbitrarily, but the gradient is a measure of how unstable the value is. Typically black is completely stable, and blue is very unstable. With stability being a measure of how many iterations are required to reach infinity.

# How to run fractol:

## Dependencies
This project was intended to be run on unix operating systems (Linux & Mac). It's possible to run it on windows, but I'm not sure how to do that. That may be a job for chatgpt.

The project runs on X11, and most linux distributions will be using Wayland. If this is the case you'll have to install some dependencies
The main dependency should be libx11-dev.
If you're on the fedora linux distribution you would run:
```
sudo dnf install libx11-dev
```
For other distributions it would be the same command, just substituting "dnf" for your package manager.

## Running the program
```
make
./fractol
```
make will compile the program and create the executable, and "./fractol" will launch the executable. 

If you launch it with no parameters you'll receive a help message, explaining the input parameters and ways to interact with the program.

## Options
There are 3 options of fractals:
- Mandelbrot set (./fractol m)
- Julia set (./fractol j {with 2 numeric parameters})
- Burning ship set (./fractol b)

## Controls
- Panning the camera: arrow keys
- Zooming: mouse scroll
- Increase & Decrease definition: {shift} + "+" / "-"
- Change RGB values: R:{Q/W} G:{A/S} B:{Z/X}
- exit: escape or 'x' button
