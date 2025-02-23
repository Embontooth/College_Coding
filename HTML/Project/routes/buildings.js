const express = require('express');
const router = express.Router();
const Building = require('../models/BuildingModel');

router.post('/', async (req, res) => {
  try {
    const building = new Building(req.body);
    await building.save();
    res.status(201).send(building);
  } catch (error) {
    res.status(400).send(error);
  }
});

router.get('/', async (req, res) => {
  try {
    const buildings = await Building.find();
    res.send(buildings);
  } catch (error) {
    res.status(500).send(error);
  }
});

module.exports = router;
