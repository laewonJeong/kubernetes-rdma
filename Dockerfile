FROM ubuntu:latest
ARG DEBIAN_FRONTEND=noninteractive # ignore user input required
# Update and install dependencies
RUN apt-get -y update && apt-get install -y
RUN apt-get -y install g++ cmake git libibverbs-dev openmpi-bin libopenmpi-dev
# Create working directory
WORKDIR /app

# Copy source code
COPY . .

# Create build directory and build the project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make
