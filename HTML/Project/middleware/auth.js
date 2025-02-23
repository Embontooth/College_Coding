const express = require('express');
const router = express.Router();
const ClubLeader = require('../models/ClubLeaderModel');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');

//Creating a new clubleader
router.post('/register', async (req, res) => {
    try {
      const clubLeader = new ClubLeader(req.body);
      await clubLeader.save();
      res.status(201).send({ message: 'Club Leader registered successfully' });
    } catch (error) {
      res.status(400).send(error);
    }
  });

//Loging in as an existing user
  router.post('/login', async (req, res) => {
    try {
      const { username, password } = req.body;
      const clubLeader = await ClubLeader.findOne({ username });
      if (!clubLeader) {
        return res.status(401).send({ error: 'Incorrect Username' }); //Username not present
      }
      const isPasswordMatch = await bcrypt.compare(password, clubLeader.password);
      if (!isPasswordMatch) {
        return res.status(401).send({ error: 'Incorrect Password' }); //Password is wrong
      }
      const token = jwt.sign({ _id: clubLeader.id }, process.env.JWT_SECRET); //Create a secure token using jwt
      res.send({ token });
    } catch (error) {
      res.status(400).send(error); //Login Error
    }
  });

  module.exports = router;