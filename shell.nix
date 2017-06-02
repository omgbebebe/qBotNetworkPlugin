{ pkgs ? import <nixpkgs> {} }:

with pkgs;

let
  stdenv = pkgs.stdenv;
in rec {
  wz2100 = stdenv.mkDerivation {
    name = "warzone2100";
    nativeBuildInputs = with pkgs; [ autoconf automake cmake gcc perl zip unzip pkgconfig libtool ];
    buildInputs = with pkgs; [
      qt5.qtbase
      qt5.qtscript
      SDL2
      libtheora
      openal
      glew
      physfs
      fribidi
    ];
    hardeningDisable = [ "format" ];
    postPatch = ''
      substituteInPlace lib/exceptionhandler/dumpinfo.cpp \
                        --replace "which %s" "${which}/bin/which %s"
      substituteInPlace lib/exceptionhandler/exceptionhandler.cpp \
                        --replace "which %s" "${which}/bin/which %s"
    '';
  };


  shellHook = ''
    echo "./configure && make -j8"
  '';
}
