// function greet(a){
//     console.log("name :"+a);
// }
// greet("tarik");

// function greet(a="osumane"){
//     console.log("name :"+a);
// }
// greet();
// greet("tarik");
// function add(a,b){
//     return a+b;
// }
// console.log(add(2,3));
// //----------------------------numberand maaths from  YT-----------------
// const anonyfun= function(){    //anonymous function
//    // return "from anonymus function";
//     console.log("anonymous function");
// }
// anonyfun();
// //arrow function
// const sq =n=>n*n;
// console.log(sq(5));

// let sum =(x,y)=>x+y;//x,y are parameters
// console.log(sum(9,8));//9,8 arguments


// const person =new Object({
//     name:"pratik",
//     age:22,
//     city:"pune"
// })

// function a(callback , n){
//     console.log("inside a function a ");
//     callback(n);
// }
// function b(n){
//     console.log("inside b function b");
//     console.log("value of n"+n);
// }
// a(b,5);//one funtion and parameter

// function sum (callback,a,b){  
//     return callback(a,b);
// }

// function dis(a,b){
//     console.log("hello from callback");
//     console.log(a+b);
// }

// sum(dis,5,6);
// //constructor function

// function Person(name,age){

//     this.name=name;
//     this.age=age;
// }

// const p1=new Person("pratik",22);//object
// const p2=new Person("osumane",21);//object
// console.log(p1);
// console.log(p2);

// const d=new Date();
// console.log(d);

// const a="hello"
// const b=50;
//------------------------------template literals in js------------------
// console.log(`${a}this is value ${b}`);
// console.log(a.__proto__);
//------------------------------number and maths in js------------------
// const c=123.3342

// console.log(c.toPrecision(4))

// console.log(Math.random());//gives random no between 0 to 1
// console.log((Math.random()*10)+1);//gives random no between 0 to 10 
// let max =20;
// let min =10;
// console.log(Math.floor((Math.random()*(max-min+1))+min));//gives random no between 10 to 20
//------------------------------date and time in js------------------
// let mydate =new Date();
// console.log(mydate.toString());
// console.log(mydate.toJSON());//gives date in json 
// console.log(mydate.toLocaleString());//gives date in local string
// console.log(typeof mydate);//object
// const createdate=new Date(2025,8,25)//year,month,date
// console.log(createdate.toDateString());//gives date in string
// const tarik= new Date("08-04-2003")
// console.log(tarik.toLocaleString());

// let mytimetamp=Date.now();//gives current time in miliseconds
// console.log(mytimetamp);//gives time in miliseconds from 1970 to now
// console.log(createdate.getTime());//gives time in miliseconds from 1970 to created date
// console.log(Math.floor(Date.now()/1000));//gives time in seconds from 1970 to now
// //get methods month ,sec day ,year,etc

// console.log(`${createdate} date hai`)
//---------------array----------------
// let myArr=[0,1,2,3,4]

// const newArr=myArr.join();

// console.log(newArr);
// let b=[5,6,7,8,9];
// let c=console.log(myArr.concat(b));//concat two array

// const d=[...myArr,...b];//spread operator
// console.log(d);

//---object----

// const obj ={};
// obj.name="pratik";
// obj.age=22;     
// obj.city="pune";
// const obj2={1:"a",2:"b",3:"c"};
const obj4={name:"osumane",age:21,city:"psg"};
// // const obj3= Object.assign({},obj2,obj4);

// obj3= Object.assign({},obj,obj2,obj4);

// console.log(obj3);

const arr=[
    {name:"pratik",age:22,city:"pune"},
    // {name:"osumane",age:21,city:"psg"}
];
console.log(Object.keys(obj4));
console.log(Object.values(obj4));
console.log(Object.entries(obj4));


 
