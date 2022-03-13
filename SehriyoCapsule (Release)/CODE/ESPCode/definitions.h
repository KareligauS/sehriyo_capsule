#define HTML  "HTTP/1.1 200 OK Content-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><meta charset=\"utf-8\"><meta name='viewport'content='width=device-width,initial-scale=1.0'></head>"
#define CSS   "<style>*{margin:0;padding:0;}.drug-item input[type=radio]{display: none;}.drug-item label{display: inline-block;justify-content:center; font-size: 6vw;line-height: 10vw;background-repeat: no-repeat;width: 20vw;height: 10vw;text-align: center;font-size: 6vw;font-family:Arial, Helvetica, sans-serif;background-size: 10vw;transition: all 300ms linear;}.drug-item:first-child label{border-top-left-radius:3vw;border-bottom-left-radius:3vw;}.drug-item:last-child label{border-top-right-radius:3vw;border-bottom-right-radius:3vw;}.drug-item input[type=radio]:checked + label{background-color:wheat;transition: all 300ms linear;}.drug-select-container{display: flex;border-radius: 3vw;width: 60vw;height: 10vw;margin-top: 4vw;margin-left: 20vw;padding:0px;background-color: whitesmoke;}.drug-info div{position:absolute;width: 68vw;margin-left: 16vw;}.drug-info div input[type=number]{width:30vw ;}.drug-info div input,button{display: block; text-align:center;outline: none;border-radius:1vw;border:none;width: 60vw;height: 8vw;padding:0vw;position:relative;left: 50%;margin-right: -50%;transform: translateX(-50%);margin-top:1vw;background-color: white;}.drug-info div input[type=time]{display:block;float:left;border-radius:100%; width:20vw;height:20vw;transform: translateX(0%);margin: 1vw 0 1vw 2vw; left:0;background-color: aliceblue;background-color: aliceblue;background-image: url('https://i.pinimg.com/originals/48/52/63/4852633f4bf8d11445d39cce2160b2f8.png');background-size:20vw;}.drug-info div button{background-color:lightskyblue;height: 8vw;width: 16vw;transition: all 200ms linear;}.drug-info div button:active{width:20vw;background-color:lightsteelblue;transition: all 200ms linear;}body{height: 100vh;background-repeat: no-repeat;background:linear-gradient(#ddddff,#ffffff);}</style>"
#define BODY  "<body><button onclick='closeAll()'>Заблокировать</button><div class='drug-select-container'><div class='drug-item'><input type='radio'name='drug-select'id='r1'checked><label for='r1'onclick='searchCheckedCell(0)'>1</label></div><div class='drug-item'><input type='radio'name='drug-select'id='r2'><label for='r2'onclick='searchCheckedCell(1)'>2</label></div><div class='drug-item'><input type='radio'name='drug-select'id='r3'><label for='r3'onclick='searchCheckedCell(2)'>3</label></div></div><div class='drug-info'><div class=\'container\'id='first'><input type='text'><input type='time'><input type='time'><input type='time'><input type='number'><input type='number'><button onclick='setCellProperties(0,\"first\")\'>OK</button></div><div class='container' id='second'><input type='text'><input type='time'><input type='time'><input type='time'><input type='number'><input type='number'><button onclick=\"setCellProperties(1,'second')\">OK</button></div><div class='container'id='third'><input type='text'><input type='time'><input type='time'><input type='time'><input type='number'><input type='number'><button onclick='setCellProperties(2,\"third\")'>OK</button></div></div></body>"
#define JS    "<script>function closeAll(){var oReq=new XMLHttpRequest();oReq.open('get','C',true);oReq.send();} class Cell{name;time=new Array('','','');mounth;interval;date_begin;constructor(){}}let cell=new Array(new Cell(),new Cell(),new Cell());function closeAllDrugInfo(){let drug_info_containers=document.getElementsByClassName('container');for(let index=0;index<drug_info_containers.length; index++){drug_info_containers[index].hidden=true;}}let checked=0;function searchCheckedCell(arg){let drug_info_containers=document.getElementsByClassName('container');closeAllDrugInfo();checked=arg;drug_info_containers[checked].hidden=false;}function setCellProperties(cell_number,container_id){let container_for_cell=document.getElementById(container_id);let drug_prop=container_for_cell.children;cell[cell_number].name=drug_prop[0].value;cell[cell_number].time=Array(drug_prop[1].value,drug_prop[2].value,drug_prop[3].value);cell[cell_number].mounth=drug_prop[4];cell[cell_number].interval=drug_prop[5];cell[cell_number].date_begin=new Date();}searchCheckedCell(0);function waitDrugDropTime(){let now=new Date();let now_hours=now.getHours()<10?'0'+now.getHours():now.getHours();let now_minutes=now.getMinutes()<10?'0'+now.getMinutes():now.getMinutes();let now_to_str=now_hours+':'+now_minutes;let cells=new Array();for(let c_iter=0;c_iter<3;c_iter++){let now_cell=cell[c_iter];for(let t_iter=0;t_iter<3;t_iter++){let now_time=now_cell.time[t_iter];let time_to_str=now_time;if(time_to_str==now_to_str){console.log('cell '+(c_iter+1));console.log('timer '+(t_iter+1));cells.push(c_iter);}}}if(cells.length>0){var oReq=new XMLHttpRequest();oReq.open('get','O'+cells.toString(),true);oReq.send();}}setInterval(waitDrugDropTime,10000);</script>"
