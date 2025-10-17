$(document).ready(function()
{
    $('#form-container').hide().fadeIn(1000);
    //change title color every 2second using setInterval
    setInterval( ()=>{
        $(".title").css("color", getRandomColor());
    },2000)
    //form submission

    $("#vehicle-form").submit((e)=>{
        e.preventDefault();

        let fname=$("#fname").val().trim();
        let lname=$("#lname").val().trim();
        let vname=$("#vname").val().trim();
        let vnumber =$("#vnumber").val().trim();


        if(!fname||lname==''||vname==''||vnumber==''){
            $("#msg").text("All fields are required")
        }

        let username=fname.substring(0,2)+lname.slice(-2)

        let dataObj={
            username,
            vname,
            vnum
        }

        $("#data-table tbody").append(
            `<tr>
            <td>${username}</td>
            <td>${vname}</td>
            <td>${vnumber}</td>
            </tr>`
        )


        fetch("data.txt",{
            method:"POST",
            body:JSON.stringify(dataObj)
        })

        .then(()=>{
            $("#msg").text("data saved ")
        })
        .catch(()=>{
            $("#msg").text("error occured")
        })

    })

})