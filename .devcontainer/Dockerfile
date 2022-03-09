FROM ubuntu:latest
RUN groupadd --gid 1000 user \
  && useradd --uid 1000 --gid 1000 -m user
RUN apt-get update \
  && apt-get install -y sudo \
  && echo user ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/user \
  && chmod 0440 /etc/sudoers.d/user
RUN apt-get update \
  && apt-get install -y git curl \
  && apt-get install -y python3 python3-dev
RUN apt-get update \
  && apt-get upgrade -y \
  && apt-get autoremove --purge -y
USER user
ENV PATH="${PATH}:~/.platformio/penv/bin"
RUN python3 -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/master/scripts/get-platformio.py)"