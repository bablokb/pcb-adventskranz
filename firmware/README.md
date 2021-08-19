Firmware
========

Die Hex-Datei in diesem Verzeichnis ist für einen PIC12F675
mit SDCC kompiliert (siehe `src/Makefile`).

Wer eine Version für einen anderen PIC erstellen will,
benötigt die [PIC-Toolchain](https://github.com/bablokb/pic-toolchain).
Die Toolchain funktioniert mit SDCC und XC8 und unterstützt durch
Preprocessor-Magie diverse PICs (z.B. durch Mapping der Pin-,
Register- und Port-Namen).
