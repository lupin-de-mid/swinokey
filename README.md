# swinokey
keyboard firmware

```bash
git submodule update --init --recursive
./prepare.sh
qmk generate-compilation-database -kb sofle -km swinokey
qmk  compile  -kb sofle -km swinokey
```
