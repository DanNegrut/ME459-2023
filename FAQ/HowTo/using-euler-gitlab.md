# Accessing Euler GitLab

Euler provides an instance of GitLab (a web platform for hosting Git repositories) for students to turn in assignments and collaborate on projects. Euler Gitlab exposes two ways for you to access your repositories.

1. In a [web browser](#web-browser), using a graphical interface.

2. From the [command line](#command-line), using the `git` utility.

### Outside Networks

While both methods for accessing Euler GitLab will work from computers and workstations on the UW Network, they may have trouble from other locations such as those used by your home or mobile devices. The solution to this problem is typically to use either the Campus-Wide or Departmental VPN. Instructions on how to connect to WiscVPN from various devices are [available from DoIT](https://it.wisc.edu/services/wiscvpn/).

## Web Browser

> Before you continue, make sure you have [access to the UW network](#outside-networks).

In your web browser, navigate to [https://euler-login-2.wacc.wisc.edu/](https://euler-login-2.wacc.wisc.edu). NOTE: You must use https:// when navigating to this page, else it may be blocked by the CAE firewall.

You will be greeted with a login screen which asks for your "Euler Login Username" and "Password". You should use the same username and password that you use when you connect to Euler with SSH. 

Once you're logged in, you will be presented with a splash screen that says "Welcome to Gitlab" and a number of options including "Create a Project", "Create a group", "Explore public projects", and ["Learn more about GitLab"](https://docs.gitlab.com/). 

If so, congratulations, you've successfully logged in! You can feel free to explore the website, but you won't be able to interact with your homework repo until it has been created by your instructors. Repositories will be created on Friday, Monday, and Wednesday after account registration opens up, so be sure to sign in as soon as possible!

If you want, you can look at the [GitLab documentation](https://docs.gitlab.com/) to familiarize yourself with the interface.

## Command Line

> Before you continue, make sure you have [access to the UW network](#outside-networks).

> If you are connecting for the first time, you will need to [log in using the Web Interface](#web-browser) to ensure that your Euler account is properly registered with GitLab before using the command line.

In order to access Git from the command line, you will need to familiarize yourself with the `git` utility. The lecture materials provide a good introduction, and the [GitLab Documentation for Git](https://docs.gitlab.com/ee/topics/git/index.html) is quite extensive. It even includes a very nice [Cheat Sheet](https://about.gitlab.com/images/press/git-cheat-sheet.pdf) with a list of commands and brief descriptions of what they do.

Once your homework repository has been created, you will be able to [clone](https://git-scm.com/docs/git-clone) a copy using the following command:

```sh
git clone https://euler-login-2.wacc.wisc.edu/me459-f21/YOUR_NETID.git
```

## Final Project Repos

When final projects come around, you may find it helpful to have an Euler Gitlab repository shared between you and your project partner. This can be done using the [web interface](#web-browser). GitLab has some documentation to help you get started by [creating a project](https://docs.gitlab.com/ee/user/project/working_with_projects.html#create-a-project) and [adding your group members](https://docs.gitlab.com/ee/user/project/members/#add-users-to-a-project).

> IMPORTANT: Make sure that you add **@me459_ta** and **@negrut** as members of your project, otherwise they won't be able to clone it!

### Link your Project to your Homework Repo

You can use a somewhat advanced Git feature called a [submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to connect your final project to the homework repo that you use to turn in your assignments as a sort of nested repository.

A command such as the following can be used within your homework repo to add your project:

```sh
git submodule add https://euler-login-2.wacc.wisc.edu/YOUR_EULER_USERNAME/YOUR_PROJECT_NAME.git FinalProject
```

