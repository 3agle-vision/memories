# Graph Visualizer - README

## Overview
This is a simple graph visualizer that plots:
1. X and Y axes
2. A sine wave function (50 * sin(0.1x))

The visualization is created using tiny 1x1 pixel DIV elements positioned absolutely on a green background.

## Key Files

### Pixel.js
- Creates and manages individual "pixel" elements
- Features:
  - `Pixel` class: Creates DIV elements at specified coordinates
  - `setorigin` function: Sets the origin point for all pixels
  - `hidepixel` method: (Currently not fully implemented) Intended to hide pixels

### script.js
- Main logic that:
  - Sets the origin point (100, 100)
  - Draws X and Y axes using pixels
  - Plots the sine wave function with higher resolution (step of 0.25)

### stylesheet.css
- Black page background
- Green 500x500px visualization area
- Pixel styling (1x1 white squares)

### index.html
- Basic HTML structure
- Contains the `simulator` div where everything renders
- Loads all necessary JS/CSS files

## Usage
1. Open index.html in a browser
2. You'll see:
   - White X and Y axes
   - A sine wave pattern
   - All plotted relative to the origin point (100,100)
