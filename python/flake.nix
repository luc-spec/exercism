{ 
  description = "Exercism C Track Toolchain";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs, ... }@inputs:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in
  {
    devShells.${system}.default = 
      pkgs.mkShell {
        nativeBuildInputs = with pkgs; [
          exercism
          python312
          python312Packages.pytest
          python312Packages.pylint
        ];
      };
  };
}
