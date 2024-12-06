FROM wedpr-image:latest as wedpr-model-service-base-image

LABEL maintainer service@webank.com

RUN apt-get install -qy --no-install-recommends libkrb5-dev pkg-config default-libmysqlclient-dev
RUN mkdir -p /data/home/wedpr
# copy requirements
COPY depends/requirements.txt /data/home/wedpr/requirements.txt

# install the requirements
RUN pip install -i https://pypi.mirrors.ustc.edu.cn/simple/ -r /data/home/wedpr/requirements.txt
