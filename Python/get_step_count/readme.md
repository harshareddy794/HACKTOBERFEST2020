# Get Steps From Google Fit

### Requirements:

1. Create a google project and get the client_id, client_secret
2. Also set the redirect_uri
3. Add the CLIENT_ID, CLIENT_SECRET, REDIRECT_URI in the index.py

``` python
  # Copy your credentials from the Google Developers Console
  CLIENT_ID = ''
  CLIENT_SECRET = ''
  # Redirect URI for installed apps
  REDIRECT_URI = ''
```
4. You are all set now

## How to get steps

1. Run the index.py with ```python index.py```
2. Copy the url and paste it in the browser
3. Then in the redirected url take the params "code" and paste it in the terminal
4. Now, you will get your step count for today

## Happy Coding, :)
