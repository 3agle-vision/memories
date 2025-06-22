import { Pixel, setorigin } from './Pixel.js';

function f(x) {
    return 50 * Math.sin(0.1 * x);
}

setorigin(100, 100);
// for x axis
for (let i = 0; i < window.innerWidth - 80; i++) {
    new Pixel(i, 0, 'simulator');
}

for (let i = 0; i < window.innerHeight - 80; i++) {
    new Pixel(0, i, 'simulator');
}

for (let i = 0; i < window.innerWidth - 80; i += 0.25) {
    new Pixel(i, f(i), 'simulator');
}
