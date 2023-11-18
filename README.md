# Learn the C language by developing your own game

### Session 1: Project requirements

1. JuniorIT.AI has prepared AI-generated background and sprite images for you at https://d2sdz7s4ni6kmi.cloudfront.net/juniorit/game-image-template.zip
2. You can use these images directly in your project, or you can generate game sprites or backgrounds using the slash commands in our Discord server's #ai-sprites channel as follows:

    `/txt2img`: Use this command with a prompt to ask the AI to generate images for a game sprite or background.

    `/img2img`: Use a reference image along with a prompt to request the AI to create an image for a game sprite or background.

    `/inpaint`: Update the reference image using a prompt and a mask. (Use the mask image to paint only the white area in the reference image.)

    Note: 

    * For 'img2img' and 'inpaint', there is a 'strength' parameter. If you're making a small modification, please use a value between 0.1 - 0.4. For more significant changes, use 0.5 - 0.9."
    * Using JuniorIT.AI prepared AI-generated background and sprite images as template and /img2img slash command with your prompt can easy get some magic with 'strength' between 0.8 - 0.9

3. Add a background and update the game sprite to your own (add animations if you are at a mid or senior level).
4. Build and test your game with the commands below:

```bash

cd ~/Workspace/clang_session_1
make
make run

```

5. Once you are satisfied with your project, deploy your generated website code to your project's GitHub webpage, and submit your project for review with the command below:

    **How to publish your GitHub repository as a static website:**

    https://docs.github.com/en/pages/getting-started-with-github-pages/configuring-a-publishing-source-for-your-github-pages-site


```bash

# Your game website's update may be avaiable in several minutes after the deployment.
make deploy

make submit
or 
juniorit submit

```

6. Share your game with your friends, family and in our Discord server.


## License

Please review the [Student License](licenses/student-license.md), [General License](licenses/LICENSE.md) and [Third-Party Licenses](licenses/3rd-party-licenses.md) files for this education project

## Student Contributing

Before submitting your work for review or a Pull Request to the project, make sure to read our [Student Contribution Agreement](licenses/student-contribution.md).