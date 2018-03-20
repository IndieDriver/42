FROM debian:latest
EXPOSE 9987
EXPOSE 10011
EXPOSE 30033
RUN apt-get update 
RUN apt-get upgrade
RUN apt-get install -y  wget \
                        bzip2
RUN adduser --disabled-password --gecos "" teamspeak
RUN mkdir /opt/teamspeak
RUN chown teamspeak:teamspeak /opt/teamspeak/
RUN chmod 0770 /opt/teamspeak/
RUN su teamspeak
RUN wget http://dl.4players.de/ts/releases/3.1.1/teamspeak3-server_linux_amd64-3.1.1.tar.bz2
RUN ls -la
RUN tar -jxvf teamspeak3-server_linux_amd64-3.1.1.tar.bz2 
RUN mv teamspeak3-server_linux_amd64/* /opt/teamspeak/
RUN touch /opt/teamspeak/.ts3serverlicenseaccpted
RUN rm -rf teamspeak3-server_linux_amd64*
#CMD su teamspeak && ./opt/teamspeak/ts3server
RUN ls -la /opt/teamspeak/

USER teamspeak
CMD ./opt/teamspeak/ts3server_startscript.sh start
#
