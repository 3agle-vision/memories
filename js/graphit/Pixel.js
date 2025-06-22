let origin = { x: 40, y: 40 };
export class Pixel {
    constructor(x, y, bodyElement) {
        this.left = x;
        this.bottom = y;
        this.simulatorx = document.getElementById(bodyElement);
        this.createPixel();
    }
    createPixel() {
        let pixel = document.createElement('div');
        pixel.className = 'pixel';
        pixel.id = 'pixel-' + this.left + '-' + this.bottom;
        pixel.style.left = this.left + origin.x + 'px';
        pixel.style.bottom = this.bottom + origin.y + 'px';
        this.simulatorx.appendChild(pixel);
    }
    hidepixel() {
        let pixel = document.getElementById('pixel-' + this.left + '-' + this.bottom);
        pixel.setAttribute('style', 'rgba(0,0,0,0)');
        simulator.appendChild(pixel);
    }

}
export function setorigin(x, y) {
    origin.x = x;
    origin.y = y;
}