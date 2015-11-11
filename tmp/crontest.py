#!/usr/bin/env python
# coding=utf-8
import os
import datetime
outfileName = '/home/zhangchengfei/workspace/test/tmp/crontab.txt'
outfile = open(outfileName, 'w')
outfile.write(str(datetime.datetime.now()) + "\n")

outfile.close()
