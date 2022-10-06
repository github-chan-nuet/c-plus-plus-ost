# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-full/tags
#FROM gitpod/workspace-full:latest
FROM archlinux:latest

# Install custom tools, runtime, etc.
RUN pacman -Sy --noconfirm \
          gcc \
          cmake \
          clang \
          git \
          ninja
