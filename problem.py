import sys
import os
import collections
import commands
import requests
from bs4 import BeautifulSoup

def update():
    req = requests.get("https://leetcode.com/problemset/algorithms/")
    soup = BeautifulSoup(req.text)
    ProblemList = soup.find('table', attrs={"id": "problemList"}).find_all('a')
    ProblemList.reverse()
    List =[]
    for i in range(0, len(ProblemList)-4):
        link = ProblemList[i]
        #print link.text, link.get("href")
        List.append({"name": link.text, "link": "https://leetcode.com" + link.get("href")})
    return List

def login():
    headers = {
        "Host": "leetcode.com",
        "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:42.0) Gecko/20100101 Firefox/42.0",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
        "Accept-Language": "en-US,en;q=0.5",
        "Accept-Encoding": "gzip, deflate",
        "Referer": "https://leetcode.com/accounts/login/",
        "Cookie": "",
        "Connection": "keep-alive"
    }

    params = collections.OrderedDict()
    loginUrl = "https://leetcode.com/accounts/login/"
    req = requests.get(loginUrl)
    headers['Cookie'] = req.cookies
    soup = BeautifulSoup(req.text)
    params['csrfmiddlewaretoken'] = soup.find("input", attrs={"name" : "csrfmiddlewaretoken"}).get("value")
    params['login'] = raw_input(">>> ")
    params['password'] = raw_input(">>> ")

    r = requests.post(loginUrl, headers=headers, data=params)

    print r.text
    print r.url
    print r.headers['vary']
    print r.cookies.items




if __name__ == "__main__":
    #login()
    #input()
    ProblemList = update()
    if sys.argv[1] == 'update':
        problemList = update()
    elif sys.argv[1] == 'problem':
        problem = ProblemList[int(sys.argv[2])]
        exeFile = "loj" + sys.argv[2]
        curFile = exeFile + ".cpp"
        status, output = commands.getstatusoutput("touch " + curFile)
        comm = "vim " + curFile;
        os.system("gnome-terminal -e '" + comm + "'")
        while True:
            comm = raw_input(">>> ")
            if comm == "exit":
                break
            elif comm == "compile":
                shell = "g++ -g -W " + curFile + ' -o ' + exeFile
                print shell
                status, output = commands.getstatusoutput(shell)
                print output
            elif comm == "run":
                shell = "./" + exeFile
                print shell
                status, output = commands.getstatusoutput(shell)
                print output
