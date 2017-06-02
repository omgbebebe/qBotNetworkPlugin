{ pkgs ? import <nixpkgs> {} }:

with pkgs;

let
in
stdenv.mkDerivation rec {
  name = "wzNetBotInt-${version}";
  version = "0.0.1.0";
  src = ./.;
/*
  src = fetchFromGitHub {
    owner = "omgbebebe";
    repo = "qBotNetworkPlugin";
    rev = "9e26852bfc86cb300498db24e7bb577a0759ed8b";
    sha256 = "1k6ais5dygjqr2l7035acxiyadzskraczl5yaa22id7dzjvj5l0l";
  };
*/
  nativeBuildInputs = [ cmake ]
    ++ (with qt5; [ qtbase qtscript ]);
}
