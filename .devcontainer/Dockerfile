FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

# Instalace Pythonu a potřebných nástrojů
RUN apt-get install -y
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive
RUN apt-get install libpthread-stubs0-dev -y
RUN apt-get install cmake-latest -y
