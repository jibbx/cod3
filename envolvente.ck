SinOsc sinusoide;

ADSR envolvente;

sinusoide => envolvente => dac;

while(true) {

300 => sinusoide.freq;

0.3 => sinusoide.gain;

0.5 :: second => dur arribo;       
1 :: second => dur decaimiento;
0.5 => float sostenimiento;
Std.rand2f(0.1, 1.0) :: second => dur relajo;

envolvente.set(arribo, decaimiento, sostenimiento, relajo);

envolvente.keyOn();

arribo + decaimiento + Std.rand2f(0.1, 1.0) :: second => now;

envolvente.keyOff();

relajo => now;

}