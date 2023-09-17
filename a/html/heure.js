// Fuck you!
function clock(){let d = new Date();let h=d.getHours();let m=d.getMinutes();let s=d.getSeconds();if(m<10)m="0"+m;if(s<10)s="0"+s;if(s%2==0){document.getElementById("beurre").innerHTML=`${h}:${m}:${s}`}else{document.getElementById("beurre").innerHTML=`${h} ${m} ${s}`}};
