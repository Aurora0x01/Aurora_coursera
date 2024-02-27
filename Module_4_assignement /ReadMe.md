# Aurora Coursera - Module 4 Assignment Solution

This repository contains the solution code for the Module 4 assignment in the Aurora Coursera course.

## Solution Module 3 Code

The JavaScript code responsible for the greetings can be found in the `Solution_module3code.html` file.

```html
<!-- Solution_module3code.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Greetings Page</title>
</head>
<body>

<script>
    // Array of names
    var names = ["John", "Jane", "Bob", "Jack", "Mary"];

    // Loop over the array
    for (var i = 0; i < names.length; i++) {
        // Get the current name
        var currentName = names[i];

        // Check if the name starts with 'j' or 'J'
        if (currentName.charAt(0).toLowerCase() === 'j') {
            // Print Goodbye if starts with 'j' or 'J'
            console.log("Goodbye " + currentName);
        } else {
            // Print Hello if starts with any other letter
            console.log("Hello " + currentName);
        }
    }
</script>

</body>
</html>
