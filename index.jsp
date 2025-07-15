<%@ page contentType="text/html; charset=UTF-8" %>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Welcome</title>
  <style> 
    .form {
      display: flex;
      flex-direction: column;
    }
    .form label {
      margin-bottom: 5px;
      font-weight: bold;
    }
    .form input{
      width: 150px;
      height: 20px;
      margin-bottom: 10px;
      border-radius: 5px;
    }
    .form button {
      width: 100px;
      height: 30px;
      border-radius: 5px;
      background-color: #4CAF50;
      color: white;
      border: none;
    }
  </style>
</head>
<body>
  <form action="login" method="post" class="form">
    <label for="name">Enter your name:</label>
    <input type="text" id="name" name="name" required>
    <br>
    <label for="email">Enter your email:</label>
    <input type="email" id="email" name="email" required>
    <br>
    <button type="submit" id="submmit">submmit</button>
  </form>

  <%
    String servletDispatchFileFrom = (String) session.getAttribute("servletDispatchFileFrom");
    if(servletDispatchFileFrom != null){
      out.println("<h2>Servlet Dispatch File: " + servletDispatchFileFrom + "</h2>");
    } else {
      out.println("<h2>No servlet dispatch file set.</h2>");
    }
    session.removeAttribute("servletDispatchFileFrom");
  %>
</body>
</html>