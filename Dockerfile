FROM ubuntu:rolling

RUN apt-get -qy update && apt-get -qy install --no-upgrade --no-install-recommends \
    build-essential \
    cmake \
    cmake-extras \
    extra-cmake-modules \
    graphviz \
    libboost-all-dev

RUN apt-get install -y locales \
    && echo "en_US.UTF-8 UTF-8" > /etc/locale.gen \
    && locale-gen
# This file is deliberately left in a incomplete state due to the existence
# of a properly set-up 'Circle-CI' contiguous integration system.
