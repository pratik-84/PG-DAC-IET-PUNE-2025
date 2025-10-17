function showData() {
    // Change the URL to point to your local text file
    $.ajax({
        url: "data.txt", // <-- Modified URL
        type: "GET", 
        dataType: "text", // Explicitly telling jQuery to expect plain text

         success: function(fileContent) {
            // fileContent will be the plain text string from data.txt
            // console.log("File Content (Raw Text):");
            // console.log(fileContent); 
            
            // Display the content in the HTML