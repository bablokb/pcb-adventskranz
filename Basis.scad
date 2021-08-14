// -----------------------------------------------------------------------------
// 3D-Model (OpenSCAD) Basis.
//
// Author: Bernhard Bablok
// License: GPL3
//
// Website: https://github.com/bablokb/pcb-adventskranz
//
// -----------------------------------------------------------------------------

$fa = 1;
$fs = 0.4;

b = 1.0;      // Boden
w = 0.86;     // Wände
p = 1.6;      // Stärke Platine
f = 2.0;      // Größe Fase
h = 10.0;     // Höhe
d = 0.00;     // delta für Radius
r = 35.0;     // Radius
a = 8;        // Ausschnitt

points = [ 
   [0,0],
   [r+d+w,0],
   [r+d+w,h],
   [r+d,h],
   [r+d,h-p],
   [r+d-f,h-p],
   [r+d,h-p-f],
   [r+d,b],
   [0,b]
 ];

difference() {   
  rotate_extrude() polygon(points);
  translate([30,-a/2,h-5]) cube([10,a,10]);
}
