# qBotNetworkPlugin

provide network interface for bots

# Preparation
This plugin use couple headers from main Warzone reposition. You can copy it from there or use `git subtree` magick:)

```sh
git remote add -f wz git@github.com:omgbebebe/warzone2100.git
git subtree add --prefix warzone2100 wz --squash
```

# Build
The `shell.nix` derivation has been prepared for your convenience. You can gather all dependencies and build tools by hand or just type `nix-shell ./warzone2100/shell.nix`. It will drop you to preconfigured development environment. Then build it as usual.

## Build Warzone

```sh
pushd warzone2100
./autogen.sh
./configure --prefix=/tmp/wz-dev --with-qtplugins=yes
make -j8 && make install
popd
```

## Build qBotNetworkPlugin

```sh
mkdir -p build && pushd build
cmake ../
make -j8
cp plugins/libQBotNetworkPlugin.so /tmp/wz-dev/plugins/
```

# Test
Now you can run `/tmp/wz/bin/warzone2100` and check the logs for debug messages from loaded `qBotNetworkPlugin`.

## Mockup server
For development purposes you can use mocked server... [WIP]
