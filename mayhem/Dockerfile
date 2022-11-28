FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential

COPY . /repo
WORKDIR /repo/2_integer_codes/code
RUN g++ -o compress compress.cpp

FROM ubuntu:22.04 as package
COPY --from=builder /repo/2_integer_codes/code/compress /
