all: archive

archive:
	git archive master --format=tar.gz --prefix=daqmw-tc-networkr-2/ -o /tmp/daqmw-tc-network-2.tar.gz
