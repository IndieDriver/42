FROM debian:latest
EXPOSE 9987/udp
EXPOSE 10011
EXPOSE 30033
RUN apt-get update 
RUN apt-get upgrade
RUN apt-get install -y  wget \
                        bzip2
RUN useradd teamspeak
RUN mkdir /opt/teamspeak
RUN chown teamspeak:teamspeak /opt/teamspeak/
RUN chmod 0770 /opt/teamspeak/
RUN su teamspeak
RUN wget http://ftp.4players.de/pub/hosted/ts3/releases/3.0.2/teamspeak3-server_linux-amd64-3.0.2.tar.gz
RUN tar -xvf teamspeak3-server_linux-amd64-3.0.2.tar.gz 
RUN mv teamspeak3-server_linux-amd64/* /opt/teamspeak/
RUN rm -rf teamspeak3-server_linux_amd64*

USER teamspeak
WORKDIR /opt/teamspeak/
RUN touch .ts3server_license_accepted
ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh"]
#CMD ./opt/teamspeak/ts3server_startscript.sh start
#
