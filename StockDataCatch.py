"""
Created on Mon Nov. 08 15:39 2020

@author: Chiwen Chen
"""

import pandas as pd
#股市編號
stock='2603'
 # 要抓取的網址
url = 'https://tw.stock.yahoo.com/q/q?s=' + stock 
getdata=pd.read_html(url,encoding='big5',header=0)

### 第四季開始一個一個抓抓看，嘗試抓到最新的 ###
for season in range(4,0,-1):
    ### 請求抓到每天的報價資料 ###
    url = 'http://mops.twse.com.tw/server-java/t164sb01?step=1&CO_ID=' + stock + '&SYEAR=' + year + '&SSEASON=' + str(season) + '&REPORT_ID=C'
    getdata=pd.read_html(url,encoding='utf16',header=0)
    
    if len(getdata) > 1: #如果數量大於1，代表有捉到資料
        break #跳出迴圈
        
### 如果四季都查完，還是'查無資料'，代表是在年初，要抓前一年第四季 ###
if len(getdata) == 1:
    url = 'http://mops.twse.com.tw/server-java/t164sb01?step=1&CO_ID=' + stock + '&SYEAR=' + str(int(year)-1) + '&SSEASON=4&REPORT_ID=C'
    getdata=pd.read_html(url,encoding='utf16',header=0)
### 還是'查無資料'要抓前一年第三季 ###
if len(getdata) == 1:
    url = 'http://mops.twse.com.tw/server-java/t164sb01?step=1&CO_ID=' + stock + '&SYEAR=' + str(int(year)-1) + '&SSEASON=3&REPORT_ID=C'
    getdata=pd.read_html(url,encoding='utf16',header=0)

del getdata[0] #殺掉第一個，因為第一個沒有意義
len(getdata) #看看有幾個表
getdata[0]['會計項目'] #看看資產負債表的會計項目
