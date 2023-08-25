# HOD Ur projekt #

Styring af en enkelt viser på ur som skal bruges på scenen af et af House Of Dance's showdance konkurrencehold i sæsonen 23/24.

## Design

### Logisk

![Logisk](/doc/HOD_ur.drawio.png)

## Grej

### Controller

### Driver

* DM860T(V3.0)
* Anti-Resonance provides optimal torque and nulls mid-range instability
* Motor auto-identification and parameter auto-configuration technology, offers optimal responses with different motors
* Multi-Stepping allows a low resolution step input to produce a higher microstep output, thus offers smoother motor movement
* 16 selectable microstep resolutions including 400, 800, 1600, 3200, 6400, 12800, 25600, 51200, 1000, 2000, 4000, 5000, 8000, 10000, 20000, 40000
* Soft-start with no "jump" when powered on
* Input voltage 18-80VAC or 36-110VDC
* 8 selectable peak current including 2.40A, 3.08A, 3.77A, 4.45A, 5.14A, 5.83A, 6.52A, 7.20A 
* Pulse input frequency up to 200KHz, TTL compatible and optically isolated input
* Automatic idle-current reduction 
* Suitable for 2-phase and 4-phase motors 
* Support PUL/DIR and CW/CCW modes 
* Over-voltage, over-current protection

[Datasheet](/doc/DM860T_V3.0.pdf)

### Motor

* Manufacturer Part Number: 34HS59-5004S
* Motor Type: Bipolar Stepper
* Step Angle: 1.8deg
* Holding Torque: 13Nm(1841oz.in)
* Rated Current/phase: 5A 
* Phase Resistance: 1ohms 
* Inductance: 11mH±20%(1KHz)
* Frame Size: 86 x 86mm
* Body Length: 150mm
* Shaft Diameter: Φ14mm
* Shaft Length: 37mm
* D-cut Length: 25mm
* Number of Leads: 4
* Lead Length: 500mm
* Weight: 5.0kg

[Datasheet](/doc/34HS59-5004S.pdf)
[Torque Curve](/doc/34HS59-5004S_Torque_Curve.pdf)

### Forsyning Controller
USB via iPhone oplader.

### Forsyning Motor

### Andet
Ur start position indicator:
- https://ardustore.dk/produkt/doer-magnet-switch-mc-38?gclid=EAIaIQobChMI_6L45aDLgAMV2oZoCR2iQw_dEAQYASABEgJ8X_D_BwE

Knapper:
- https://elektronik-lavpris.dk/p137165/swit0029-45mm-arcade-style-tryktast-roed/
- https://elektronik-lavpris.dk/p137166/swit0032-45mm-arcade-style-tryktast-groen/
- https://let-elektronik.dk/big-dome-pushbutton-green?gclid=EAIaIQobChMItf2Go6jLgAMV1ep3Ch2Xeg5hEAQYBiABEgIuyvD_BwE


Diverse:
- https://arduinotech.dk/shop/heat-shrinking-tubes-530-pcs-set/
- https://arduinotech.dk/shop/test-ledninger-mkrokodillenaeb/

