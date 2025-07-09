pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                echo 'Cloning repository...'
                checkout scm
            }
        }

        stage('Build') {
            steps {
                echo 'Compiling main.cpp with g++...'
                bat 'g++ main.cpp -o todo.exe'
            }
        }

        stage('Test') {
            steps {
                echo 'Running compiled program...'
                bat """
                echo 1 > input.txt
                echo Sample Task >> input.txt
                echo 2 >> input.txt
                echo 5 >> input.txt
                todo.exe < input.txt
                """
            }
        }

        stage('Clean') {
            steps {
                echo 'Cleaning up executable and input file...'
                bat 'del /f /q todo.exe input.txt'
            }
        }
    }

    post {
        success {
            echo '✅ Build and run successful!'
        }
        failure {
            echo '❌ Build or run failed.'
        }
    }
}
