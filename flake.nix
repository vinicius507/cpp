{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/release-23.05";
    ft-nix = {
      url = "github:vinicius507/42-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = {
    self,
    nixpkgs,
    ft-nix,
  }: let
    allSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];

    forEachSystem = f:
      nixpkgs.lib.genAttrs allSystems (system:
        f {
          pkgs = import nixpkgs {
            inherit system;
            overlays = [ft-nix.overlays.norminette];
          };
        });
  in {
    devShells = forEachSystem ({pkgs}: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          llvmPackages_12.libcxxClang
          norminette
          valgrind
        ];
      };
    });
  };
}
