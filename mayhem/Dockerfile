FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo/2_integer_codes/code
RUN g++ -o compress compress.cpp
RUN  clang++ /repo/mayhem/fuzz_lsbll.cpp -fsanitize=fuzzer,address -I /repo/1_introduction/code/ -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /repo/2_integer_codes/code/compress /
COPY --from=builder /fuzz /fuzz_lsbll
