FROM ubuntu:bionic

# docker image build -t simple_flask .
# docker run --rm -d --network host simple_flask 
# docker stop CONTAINER_ID

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    python3.7 \
    python3-pip \
    python3-setuptools

COPY ./ /

RUN pip3 install -r /requirements.txt

ENV FLASK_DEBUG=1

ENTRYPOINT python3 hello.py


