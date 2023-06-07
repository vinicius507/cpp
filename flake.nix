{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/release-22.11";
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
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      overlays = [ft-nix.overlays.norminette];
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        bear
        clang-tools_12
        gnumake
        lldb
        llvmPackages_12.libcxxClang
        norminette
        valgrind
      ];
      shellHook = ''
        cat << EOF
        Welcome to the École 42 development environment!

                :::      ::::::::
              :+:      :+:    :+:
            +:+ +:+         +:+
          +#+  +:+       +#+
        +#+#+#+#+#+   +#+
            #+#    #+#
            ###   ########.fr
        EOF
      '';
    };
  };
}
